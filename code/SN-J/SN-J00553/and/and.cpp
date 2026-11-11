#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	/*int n,m;
	long long s[200005],b[200005],a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		while(s[i]>=1){
			b[i]*=10;
			b[i]+=s[i]%2;
			s[i]/=2;	
		}
		while(b[1]>=1){
			a[i]*=10;
			a[i]+=b[i]%10;
			b[i]/=10;
		}
				
	}
	sort(a+1,a+n+1);
	long long maxn[200005];
	for(int i=m;i>=1;i--){
		maxn[i]=a[i];
	}
	string z[200005]=0;
	for(int i=1;i<=m-1;i++){
		if(maxn[i]%10==maxn[i+1]%10){
			if(maxn[i]%10==1){
				z[1]+='1';
			}else{
				z[1]+='0'
			}
			
		}else{
			z[1]+='0';
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=(int)z[i]
	}
	
	
	*/
	int n,m;
	long long s[200005],maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]>maxn){
			maxn=s[i];
		}		
	}
	cout<<maxn;
	return 0;
}





