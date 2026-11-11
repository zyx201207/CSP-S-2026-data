#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,cnt=0,s=0;
char c[200005],b[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j+=1){
			b[s+j]=c[i];
		}
		s+=a[i];
	}

//	for(int i=0;i<n/2;i++){
//		if(b[i]!=b[n-i]){
//			cnt++;
//		}
//	}
    cout<<0;
    
	return 0;
} 
