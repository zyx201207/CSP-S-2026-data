#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,a[N],ans,midd;

inline bool cmp(int a,int b){
	return a<b;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	// ΉΐÒ»ΟΒ£¬Υβ·έ΄ϊΒλ 45-75 ·Φίχίχίχ ~
	// ¶ξ£¬΄σΡωΐύ 4 Ήύ²»ΑΛΞΨΞΨΞΨ ~  ²»»αΣΕ»―ΞΨΞΨΞΨ ~ 
	// luogu:1399773 
	// Χά·Φ 45 Δά¶ώµΘ½±Βπ£Ώ ΞΨΞΨΞΨ
	/* ίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχ
	ίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχ
	ίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχ*/ 
	
	//ΞΨΞΨ£¬T2 ²»»αΠ΄ΞΨΞΨΞΨ 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	bool tp1=true,tp2=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			tp1=false;
			break;
		}
	}
	for(int i=1;i<=n-1;i++){
		if(a[i]!=a[i+1]-1){
			tp2=false;
			break;
		}
	}
//	if(tp1||tp2){
//		int mid;
//		if(n%2!=0)
//			mid=ceil((a[n/2+1]+a[n/2])*1.0/2);	
//		else{
//			int cmid=ceil(n*1.0/2);
//			mid=a[cmid];
//		}
//		int cnt=0;
//		for(int i=1;i<=n;i++){
//			if(a[i]>mid) break;
//			cnt+=mid-a[i];
//			if(cnt>m) break;
//			ans++;
//		} 
//		cout<<ans;
//	}
	for(int i=1;i<=n;i++){
		int cnt=0,cntk=0;
		for(int j=1;j<=i;j++){
			if(a[j]>a[i]){
				break;
			}   
			cntk+=a[i]-a[j];
			if(cntk>m) break;
			cnt++;
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
} 
