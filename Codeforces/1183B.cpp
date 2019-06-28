#include<bits/stdc++.h>
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
const int L=1e5+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll co,temp,cur,n,k,q;
ll a[L];
bool check(ll val)
{
	FOR(i,0,n)
	{
		if(abs(a[i]-val)>k)return 0;
	}
	return 1;
}
void ser()
{
	cin >> n >> k;
	ll mx = -1, mn = INT_MAX;
	FOR(i,0,n){cin >> a[i];mx = max(mx,a[i]);mn = min(mn,a[i]);}
	ll l=mx-k,r=mn+k,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(!check(r))r=l;
	if(!check(l))
	{
		cout<<"-1\n";
		return;
	}
	cout<<r<<ln;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>q;
	 	while(q--)
	 	ser();
		return 0;
}