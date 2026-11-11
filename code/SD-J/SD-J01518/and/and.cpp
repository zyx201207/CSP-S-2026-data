#include<bits/stdc++.h>  //40·Ö×óÓÒ 
using namespace std;
long long n,m,a[200005],bb[100005];
//queue <int> b;
void aaa(){
	for(int i=2;i<=n;i++){
		bb[i]=bb[i-1]+a[i];
		//b.push(bb[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bb[1]=a[1];
	//b.push(a[1])
	aaa();
//	b[1]=a[1];
	for(int i=1;n!=m;i++){
		if(i==n){
			i=1;
		}
		if(bb[i]=bb[i+1]){
			for(int j=i;j<=n-1;j++){
				bb[j]=bb[j+1];
				a[j]=a[j+1];
			}
			n--;
			i--;
		}	
	}
	int ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0; 
}

