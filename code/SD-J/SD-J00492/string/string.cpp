#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],x,i=1,j=1;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int k=1;k<=n;k++)
		cin>>a[k]>>b[k];
	j=n;
	while(i+1<=j){
		if(b[i]!=b[j]){
			if(a[i]<a[j]){
				x+=a[i];
				a[j]-=a[i];
				i++;
			}else if(a[i]==a[j]){
				x+=a[i];
				a[i]=0,a[j]=0;
				i++,j--;
			}else if(a[i]>a[j]){
				x+=a[j];
				a[i]-=a[j];
				j--;
			}
		}else{
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else if(a[i]==a[j]){
				a[i]=0,a[j]=0;
				i++,j--;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
		}
	}
	cout<<x;
}
