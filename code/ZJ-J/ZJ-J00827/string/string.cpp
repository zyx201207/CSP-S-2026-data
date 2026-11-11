#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string h="";
ll a[200005],sum;
char k[200006];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>k[i];
	}
	for(int i=0,j=n-1;i<=j;){
//		cout<<k[i]<<' '<<a[i]<<' '<<k[j]<<' '<<a[j]<<'\n';
		if(k[i]==k[j] && a[i]!=a[j] && abs(i-j)>=1){
			int x=a[i],y=a[j];
			if(x>=y){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}
		else if(k[i]!=k[j]){
//			cout<<"\njin\n";
			int x=a[i],y=a[j];
//			cout<<k[i]<<' '<<a[i]<<' '<<k[j]<<' '<<a[j]<<'\n';
//			cout<<a[i]<<' '<<a[j]<<"    "<<k[i]<<' '<<k[j]<<'\n';
			if(x<=y){
				a[j]-=a[i];
				sum+=a[i];
//				cout<<k[i]<<' '<<a[i]<<' '<<k[j]<<' '<<a[j]<<'\n';
				i++;
			}else{
				a[i]-=a[j];
				sum+=a[j];
//				cout<<k[i]<<' '<<a[i]<<' '<<k[j]<<' '<<a[j]<<'\n';
				j--;
			}
		}else{
			i++;
			j--;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}