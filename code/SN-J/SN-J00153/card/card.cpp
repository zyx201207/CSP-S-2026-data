#include <bits/stdc++.h>
using namespace std;
int a[100000005],b[100000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x,lt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int k=0;k<n;k++){
	for(int i=n-1;i>=k;i--){
		for(int j=i+1;j<n;j++){
			if(b[i]==b[j]){
				x=j;
				lt++;
				break;
			}
		}
	}
	if(lt==0){
		x=k;
	}
	for(int i=x;i<n;i++){
		a[b[i]]++;
	}
	lt=0;
}
    sort(b,b+n);
    for(int i=0;i<n;i++){
    	if(a[b[i]]!=-1){
    		cout<<a[b[i]]<<' ';
    		a[b[i]]=-1;
		}
	}
	
}
