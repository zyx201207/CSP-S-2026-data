#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],len,z[300005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		long long len=0,d;
		for(int j=i;j<=n;j++){
			len++;
			
			if(z[a[j]]!=0){
	//			cout<<"aaa";
				len=1;
				b[1]=a[j];
				d=a[j];
			}else{
	//			cout<<"bbb";
				z[a[j]]=len;
				b[len]=a[j];
			}
	//		cout<<len<<"lll";
		
		}
		t[d]++;
		
	}
	for(int i=1;i<=m;i++){
		t[i]=t[i-1]+t[i];
		cout<<t[i]<<' ';
	}
	
//	cout<<len;
//	for(int i=1;i<=len;i++){
//		cout<<b[i]<<"aaa";
//	}
	
	return 0;
}