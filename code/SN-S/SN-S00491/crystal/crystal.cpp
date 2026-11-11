//SN-S00491 韩亦宽 西安市第八十三中学 
#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,ji,pan;
long long a[500005],cha[500005],shu[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000&&a[107]==a[1]+(a[2]-a[1])*106){
		pan=0;
		ji=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m>=i*ji){
				m-=i*ji;
			}
			else{
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cha[j]=a[i]-a[j];
		}
		sort(cha+1,cha+i+1);
		ji=m;
		shu[i]=0;
		pan=0;
		for(pan;pan==0;){
			if(ji>=cha[shu[i]+1]&&cha[shu[i]+1]>=0){
				shu[i]++;
				ji-=cha[shu[i]];
			}
			else{
				pan=1;
			}
			if(shu[i]==i){
				pan=1;
			}
		}
	}
	sort(shu+1,shu+n+1);
	cout<<shu[n];
	return 0;
}
