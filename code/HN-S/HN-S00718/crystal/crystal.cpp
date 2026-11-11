#include<iostream> 
#include<cstdio>
using namespace std;
int a[500007],s[500007],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int k=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		if(a[i]<a[j]){
			k=a[i];
			a[i]=a[j];
			a[j]=k;
		}
	} 
	int l=m,o=1;
	for(int	i=1;i<n;i++){
		
		for(int j=i-1;j>=0;j--){
			l-=a[i]-a[j];
			
			o++;
			if(l<0){
				 
				break;
			}
			
		}
		
		if(l<0)o--;
		
		l=m;
		ans=max(ans,o);
		o=1;
	}
	cout<<ans;
	return 0;
} 
