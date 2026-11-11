#include<bits/stdc++.h>
using namespace std;
struct hui{
	int s;long long m;
	char c;
};
long long n,sum=0,ans=0;
hui a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		sum+=a[i].s;
		a[i].m=sum;
	}
	long long f=sum/2+sum%2;
	int wz;
	for(int i=1;i<=n;i++){
		if(a[i].m>=f){
			wz=i;
			break;
		}
	}
	int wz2=wz;
	a[wz].s-=2*min(abs(f-a[wz].m),abs(f-a[wz-1].m))+sum%2;
	if(f>(a[wz].m+a[wz-1].m)/2){
		wz2++;
	}else{
		wz--;
	}
	//cout<<sum<<' ';
	//cout<<wz<<' '<<wz2<<' '<<sum<<' '<<f<<endl;
	int j;
	while(wz>0&&wz2<=n){
		if(a[wz].s>0){
			//cout<<wz<<' '<<a[wz].s<<' '<<a[wz].c<<' '<<wz2<<' '<<a[wz2].s<<' '<<a[wz2].c<<endl;
			j=min(a[wz].s,a[wz2].s);
			a[wz].s-=j;
			a[wz2].s-=j;
			if(a[wz].c!=a[wz2].c){
				ans+=j;
			}

		}if(a[wz].s==0){
				wz--;
			}
			if(a[wz2].s==0){
				wz2++;
        }
	}
	cout<<ans<<endl;
	//cout<<wz<<' '<<wz2;
return 0;
}
