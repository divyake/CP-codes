#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e5+7;
std::vector<int> v[L];
ll val[L], ans;
pii subtree[L];
void dfs(int vertex, int parent = -1)
{
	ll ret = 0;
	trace(v[vertex],  x)
	{
		if(x != parent)
		{
			dfs(x, vertex);
			subtree[vertex].F = max(subtree[vertex].F, subtree[x].F);
			subtree[vertex].S = min(subtree[vertex].S, subtree[x].S);
		}
	}
	val[vertex] -= subtree[vertex].F;
	val[vertex] -= subtree[vertex].S;
	if(val[vertex] > 0)subtree[vertex].F += val[vertex];
	else subtree[vertex].S += val[vertex];
	// debug(vertex, val[vertex], subtree[vertex].F, subtree[vertex].S);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, a, b;
	 	cin >> n;
	 	FOR(i,0,n-1)
	 	{
	 		cin >> a >> b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	FOR(i,1,n+1)cin >> val[i];
		dfs(1);
		cout<<subtree[1].F + abs(subtree[1].S);
		return 0;
}