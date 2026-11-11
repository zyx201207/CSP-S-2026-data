#include<iostream>
#include<cstdio>
using namespace std;
int a[200005];
char c[200005];
int n;
long long i,j,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	j=n;
	while(i<=j){
		if(a[i]>a[j]){
			if(c[i]==c[j]){
				a[i]-=a[j];
				a[j]=0;
				j--;
			}else{
				a[i]-=a[j];
				ans+=a[j];
				a[j]=0;
				j--;	
			}
		}else{
			if(c[i]==c[j]){
				a[j]-=a[i];
				a[i]=0;
				i++;
			}else{
				a[j]-=a[i];
				ans+=a[i];
				a[i]=0;
				i++;	
			}
		}
	}
	cout<<ans;
	return 0;
}
