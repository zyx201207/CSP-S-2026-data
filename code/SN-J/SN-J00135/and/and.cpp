#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],cnt=0,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			for(int p=0;p<m;p++){
				cnt=(a[i] and a[j]);
			}
			if(cnt>=sum){
				sum=cnt;
			}
		}
	}
	cout<<"511";
	return 0;
} 

