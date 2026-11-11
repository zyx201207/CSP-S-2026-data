#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	long long cnt=0;
	for(int i=0,j=n-1;i<j;){
		if(c[i]==c[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				i++;
				j--;
			}
		}else{
			if(a[i]<a[j]){
				a[j]-=a[i];
				cnt+=a[i];
				i++;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				cnt+=a[j];
				j--;
			}else{
//				cout<<a[i]+cnt<<endl;
				cnt+=a[i];
				i++;
				j--;
			}
		}
//		cout<<i<<" "<<j<<" ";
	}
	cout<<cnt;
	return 0;
} 


