#include<bits/stdc++.h>
using namespace std;
long long a[2000005],n,d;
unsigned long long s;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c>10&&c<=12){
		while(t--){
			s=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=2;i<=n;i++)s+=((((a[2]-a[1])*(i-1))%d!=0)*(((a[2]-a[1])*(i-1)+d-1)/d)==2)*(n-i+1);
			cout<<s<<"\n";
		}
	}
	else{
		while(t--){
			s=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					if(!(d<a[j]-a[i]&&(2*d>a[j]-a[i])))continue;
					int f=0;
					for(int k=i+1;k<j;k++){
						if(a[k]-a[i]<=d&&a[j]-a[k]<=d)f++;
					}
					if(f!=2)continue;
					long long sa=1,sb=1;
					int k=j+1;
					while(1){
						if((k>n||!(a[k]-a[k-1]<=d&&a[k]-a[j-1]>d)))break;
						k++;
						sa++;
					}
					k=i-1;
					while(1){
						if((k<1||!(a[k+1]-a[k]<=d&&a[i+1]-a[k]>d)))break;
						k--;
						sb++;
					}
					s+=sa*sb;
				}
			}
			cout<<s<<"\n";
		}
	}
	return 0;
}
//10 pts aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa nonononononononononononononononononononononononononononono
//whyyyyyyyyyyyyy ccf nb!!!!!
//yao 3= le!!!!!!!!!!!!!!!!!!!!!noooooooooooooooooooooooooooooooooooooooooooo
//total:178pts
