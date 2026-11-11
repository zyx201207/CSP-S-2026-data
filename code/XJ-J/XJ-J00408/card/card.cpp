#include<bits/stdc++.h>
using namespace std;
long long a[1000000],zhuomian[1000000],jilu[1000000],d[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){//mei yi ju
		int ps=0;
		for(int j=i;j<=n;j++){//chu pai
			jilu[a[j]]++;//shi fou da yu er ji lu
			if(a[a[j]]<2){
				ps++;
				zhuomian[ps]=a[j];//pan duan
			}
			else{//qing kong zhuo mian
				for(int x=ps;x>=1;x--){
					if(zhuomian[x]==a[j]){
						jilu[zhuomian[x]]=0;
						ps-=x;
						break;
					}else{
						jilu[zhuomian[x]]=0;
					}
				}
				zhuomian[ps+1]=a[j];
				jilu[a[j]]++;
			}
		}
		for(int x=1;x<=ps+1;x++){
			d[zhuomian[x]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}