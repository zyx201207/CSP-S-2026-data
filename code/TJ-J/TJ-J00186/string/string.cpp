#include<bits/stdc++.h>
using namespace std;
long long a[100000010];
char c[110];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0,x=0,b=0;
	string s="",d="";
	bool f=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(a[i]>x){
			x=a[i];
			b=i;
		}
		for(int j=1;j<=a[i];j++){
			s+=c[i];
			m++;
		}
	}
	for(int i=m-1;i>=0;i--){
		d+=s[i];
	}
	for(int i=0;i<m;i++){
		if(s[i]!=d[i]){
			f=false;
			break;
		}
	}
	if(f){
		cout<<"0";
	}else{
		long long sum=1;
		for(int i=1;i<=n;i++){
			if(c[i]==c[i+1]){
				sum++;
			}
		}
		if(b==1){
			if(a[b]>(a[b+1]+a[b+2])){
				cout<<sum*(a[b+1]+a[b+2]);
			}else{
				for(int i=b+1;i<=n;i++){
					if(c[b]==c[i]){
						x--;
					}
				}
				cout<<x*sum;
			}
		}else if(b==n){
			if(a[b]>a[b-1]+a[b-2]){
				cout<<sum*(a[b-1]+a[b-2]);
			}else{
				for(int i=b+1;i<=n;i++){
					if(c[b]==c[i]){
						x--;
					}
				}
				cout<<x*sum;
			}
		}else{
			if(a[1]>a[n]){
				x=a[1];
			}else{
				x=a[n];
			}
			cout<<x*sum;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
