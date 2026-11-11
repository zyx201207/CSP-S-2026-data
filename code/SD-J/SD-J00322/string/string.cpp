#include<bits/stdc++.h>
//Trick||Treat!
using namespace std;
const int N=2e5+10;
int a[N];
string s[N];
int n,l;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int j=n;
	for(int i=1;i<=n;i++){
		int k=i;
		while(a[j]<=0){
			a[j-1]+=a[j];
			a[j]=0;
			j--;
		}
		while(a[k]<=0){
			a[k+1]+=a[k];
			a[k]=0;
			k++;
		}
		if(k>=j) break;
		if(s[i]==s[j]){
			if((i+1==j)||(i-1==j)||(i==j)){
				continue;
			}
			if(a[i]>=a[j]){
				cout<<a[i]-a[j]<<endl;
				ans+=a[i]-a[j];
				a[j-1]-=(a[i]-a[j]);
				a[j]-=a[i];
				a[i]=0;
			}else{//a[i]<a[j]
				cout<<a[j]-a[i]<<endl;
				ans+=a[j]-a[i];
				a[i+1]-=(a[j]-a[i]);
				a[i]-=a[j];
				a[j]=0;
			}
			
		}else{
			ans+=a[i];
			cout<<a[i]<<endl;
			a[j]-=a[i];
			a[i]=0;
			if(a[j]<=0){
				a[j-1]+=a[j];
				a[j]=0;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
