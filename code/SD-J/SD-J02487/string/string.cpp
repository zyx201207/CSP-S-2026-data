#include<bits/stdc++.h>
using namespace std;
int n,b[214514],f;
long long d,k,a;
char c[214514];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
	}
		f=n;
		for(int i=1;i<=n;){
			if(c[i]!=c[f]){
				a+=min(b[i],b[f]);
			}
			if(b[i]>b[f]){
				b[i]-=b[f];
				f--;
			}else if(b[i]==b[f]){
				f--;
				i++;
			}else{
				b[f]-=b[i];
				i++;
			}if(i>f){
				break;
			}
		}
	cout<<a;
}
