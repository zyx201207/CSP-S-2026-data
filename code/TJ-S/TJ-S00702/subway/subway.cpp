#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int nm[550000],mn,num,ans,k,zen,p,l,k2;
struct arr{
	long long zhan;
	long long time;
};
arr a[1000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>nm[i];
	}
	cin>>k;
	int k1=k;
	for(int j=1;j<=k;j++){
		cin>>p>>l;
		a[p].zhan=p;
		a[p].time=l;
	}
	for(int i=2;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>p>>l;
			for(int o=0;o<k1;o++){
				if(a[o].zhan==p){
					mn=1;
				}
				if(a[o].zhan==p and a[o].time>l){
					a[o].time=l;
					mn=1;
					break;
				}
			}
			if(mn==0){
				a[p].zhan=p;
				a[p].time=l;
			}
			mn=0;
		}
		k1=k;
	}
	for(int i=0;i<q;i++){
		cin>>p>>l;
		for(int j=p;j<=l;j++){
			num+=a[j].time;
			num+=nm[j];
		}
		cout<<num<<" ";
		num=0;
	}
}
