#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long q=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	if(n>10){
		int l=0;
		for(int i=0,j=n;i<n,j>=0;i++){
			j--;
			if(a[i]==a[j]){
				if(b[i]==b[j]){
					
				}else{
					q=q+a[i];
					//b[j]=b[i];
				}
			}else{
				if(b[i]==b[j]){
					if(n==2){
						
					}else{
						if(a[i]>a[j]){
							q=q+a[i]-a[j];
						}else{
							q=q-a[i]+a[j];
						}
					}
				}else{
					if(a[i]>a[j]){
							q=q+a[i]+a[i]-a[j];
						}else{
							q=q+a[j]+a[j]-a[i];
						}
				}
			}
		}
		cout<<q/2;
	}else{
		string s,c;
		int l=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<a[i];j++){
				s[l]=b[i];
				l++;
			}
		}
		for(int i=0,j=l-1;i<l;i++){
			c[j]=s[i];
			j--;
		}
		
		for(int i=0;i<l;i++){
			if(s[i]!=c[i]){
				c[i]=s[i];
				s[l-i-1]=c[i];
				q++;
			}
		}
		cout<<q;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}