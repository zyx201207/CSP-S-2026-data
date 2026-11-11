#include<bits/stdc++.h>
using namespace std;
long long a[5000086];
long long cha[5003008];
int main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
    long long n,q,he=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	he+=a[i];
	}
	if(he>=n){
		he/=n;
	}
	long long zhong=1000000000086,m;
	for(int i=1;i<=n;i++){
		if(he>a[i]){
			if(zhong>=(he-a[i])){
				zhong=(he-a[i]);
				m=i;
			}
		}else if(he<a[i]){
			if(zhong>=(a[i]-he)){
				zhong=(a[i]-he);
				m=i;
			}
		}else{
			m=i;
			zhong=0;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[m]>a[i]){
			cha[i]=a[m]-a[i];
		}else{
			cha[i]=a[i]-a[m];
		}
	}
	sort(cha+1,cha+n+1);
	long long hr=0,t=0;
	for(int i=1;i<=n;i++){
		hr+=cha[i];
		t++;
		if(hr+cha[i+1]>q){
			cout<<i;
			break;
		}
	}
}
//Oct31==Dec25?


