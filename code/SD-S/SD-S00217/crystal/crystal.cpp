#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=5e5+100;
ull numb[N],cha[N],su[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ull n,m;
	cin>>n>>m;
	for(ull i=1;i<=n;i++){
		cin>>numb[i];
	}
	if(n==1){
		cout<<1;
		return 0;	
	}
	sort(numb+1ll,numb+n+1ll);
	ull l=1;
	ull ans=0;
	for(ull i=2;i<=n;i++){
		su[i]=su[i-1]+(numb[i]-numb[i-1]);
		cha[i]=cha[i-1]+(numb[i]-numb[i-1])*(i-l);
		while(cha[i]>m&&l<i){
//		cout<<l<<":"<<i<<" "<<cha[i]<<endl;
			l++;
			cha[i]-=su[i];
			su[i]-=(numb[l]-numb[l-1]);
		}
		if(cha[i]<=m)ans=max(ans,i-l+1);
		if(l==i){
			cha[i]=0;
		}
//		cout<<l<<":"<<i<<" "<<cha[i]<<endl;
	}
	cout<<ans;
	return 0;
}
