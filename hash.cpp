#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 5003;
int n, m;

const pair<int,int> base = {67, 71};
const pair<int,int> mod = {1000000007, 1000000009};
pair<int,int> has[N];
pair<int,int> pw[N];
string s;
pair<int,int> ip[N];

#define fi first
#define se second

int fp(int _x, int _y, int _mod) {
	int _res = 1;
	while(_y){
		if(_y&1) _res = _res*_x%_mod;
		_x = _x*_x%_mod;
		_y >>= 1;
	}
	return _res;
}
pair<int,int> range(int l, int r){
	pair<int,int> res = has[r];
	res.fi -= has[l - 1].fi;
	res.se -= has[l - 1].se;
	res.fi %= mod.fi;
	res.se %= mod.se;
	if(res.fi < 0) res.fi += mod.fi;
	if(res.se < 0) res.se += mod.se;
	res.fi *= ip[l - 1].fi;
	res.se *= ip[l - 1].se;
	res.fi %= mod.fi;
	res.se %= mod.se;
	return res;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> s;
	pw[0] = {1, 1};
	for(int i = 1 ; i <= n ; i ++){
		int tc = (s[i - 1] - 'a' + 1);
		pw[i].fi = pw[i - 1].fi*base.fi%mod.fi;
		pw[i].se = pw[i - 1].se*base.se%mod.se;
		has[i].fi = (has[i - 1].fi + tc*pw[i].fi)%mod.fi;
		has[i].se = (has[i - 1].se + tc*pw[i].se)%mod.se;
	}
	ip[n].fi = fp(pw[n].fi, mod.fi - 2, mod.fi);
	ip[n].se = fp(pw[n].se, mod.se - 2, mod.se);
	for(int i = n - 1 ; i >= 0 ; i --){
		ip[i].fi = ip[i + 1].fi * base.fi % mod.fi;
		ip[i].se = ip[i + 1].se * base.se % mod.se;
	}
}

