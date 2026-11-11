#include<bits/stdc++.h>
using namespace std;
char a[10000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0,j=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	int x;
    	char y;
    	cin>>x>>y;
    	for(int k=j+1;k<=j+x;k++){
    		a[k]=y;
		}
    	j+=x;
	}
    for(int i=j;i>j/2;i--){
    	if(a[i]!=a[j-i+1]){
    		sum++;
		}
	}
	cout<<sum;
    return 0;
}

