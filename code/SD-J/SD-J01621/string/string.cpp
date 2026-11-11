#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt=0;
long long z[200005];
char x[200005];;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long s=n;
	for(int i=1;i<=n;i++){
		cin>>z[i]>>x[i];
	}
	for(int i=1;i<=n;i++){
		if(i<n/2&&x[i]==x[i-1]){
			z[i]+=z[i-1];
			z[i-1]=0;
			s--;
		}else if(i>=n/2&&x[i]==x[i+1]){
			z[i]+=z[i+1];
			z[i+1]=0;
			s--;
		}
	}
	if(s==1){
		cout<<0;
		return 0;
	}
	int c=n/2;
	for(int i=1,j=n;i<=c,j>=c;i++,j--){
		if(z[i]&&z[j]){
			if(x[i]==x[j]){
				continue;
			}else{			
			//cout<<z[i]<<" "<<z[j]<<" "<<z[i]-z[j];
				cnt+=min(z[i],z[j]);
			}
		}else if(z[i]){
			while(!z[j]){
				j--;
			}
		}else if(z[j]){
			while(!z[i]){
				i++;
			}
		}
		if(s==2){
		cout<<min(z[i],z[j]);
		return 0;
		}
	}
	cout<<cnt;
	return 0;
}
