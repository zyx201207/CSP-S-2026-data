#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define File(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define LL long long
#define fi first
#define se second
const int N = 2e6 + 10;
int n; LL d;
LL x[N];
int Le[N],Ri[N];
LL valL[N],valR[N];
bool visL[N],visR[N];
void solve(){
	cin >> n >> d;
	for(int i=1;i<=n;i++)
		cin >> x[i];
	for(int i=1;i<=n;i++)
		visL[i] = visR[i] = 0;
	int L = 1,R = n;
	for(int i=1;i<=n;i++){
		while(L < i && x[i] - x[L] > d) L ++ ;
		Le[i] = L;
	}
	for(int i=n;i>=1;i--){
		while(R > i && x[R] - x[i] > d) R -- ;
		Ri[i] = R;
	}
	for(int i=1;i<n;i++){
		if(Le[i] == Le[i+1]) valL[i] = 0;
		else
			valL[i] = valL[Le[i]] + (Le[i+1] - Le[i]);
	}
	for(int i=n;i>1;i--){
		if(Ri[i] == Ri[i-1]) valR[i] = 0;
		else
			valR[i] = valR[Ri[i]] + (Ri[i] - Ri[i-1]);
	}
	LL ans = 0;
	for(int i=2;i<n-1;i++){
		if(valL[i+1] == 0 || valR[i] == 0) continue;
		if(Le[i+1] > i || Ri[i] < i + 1) continue;
		LL vL,vR;
		vL = valL[i+1]; vR = valR[i];
		vL = vL - (Le[i+2] - Le[i+1]) + (min(Le[i+2],i) - Le[i+1]);
		vR = vR - (Ri[i] - Ri[i-1]) + (Ri[i] - max(Ri[i-1],i+1));
		if(vL * vR > 0){
			visL[i+1] = 1;
			visR[i] = 1;
		}
	}
	for(int i=1;i<=n;i++)
		valL[i] = valR[i] = 0;
	for(int i=1;i<n;i++){
		if(Le[i] == Le[i+1]) valL[i] = 0;
		else{
			valL[i] = (visL[Le[i]] ? 0 : valL[Le[i]]) + (Le[i+1] - Le[i]);
		}
	}
	for(int i=n;i>1;i--){
		if(Ri[i] == Ri[i-1]) valR[i] = 0;
		else
			valR[i] = (visR[Ri[i]] ? 0 : valR[Ri[i]]) + (Ri[i] - Ri[i-1]);
	}
	for(int i=2;i<n-1;i++){
		if(valL[i+1] == 0 || valR[i] == 0) continue;
		if(Le[i+1] > i || Ri[i] < i + 1) continue;
		LL vL,vR;
		vL = valL[i+1]; vR = valR[i];
		vL = vL - (Le[i+2] - Le[i+1]) + (min(Le[i+2],i) - Le[i+1]);
		vR = vR - (Ri[i] - Ri[i-1]) + (Ri[i] - max(Ri[i-1],i+1));
		ans += vL * vR;
	}
	cout << ans << "\n";
	return ;
}
int main(){
	IOS;
	File("migrate");
	int c,T;
	cin >> c >> T;
	while(T -- )
		solve();
	return 0;
}