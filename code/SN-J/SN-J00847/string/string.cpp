//牟镇嘉 SN-J00847 西安汇知中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int x,b=0,n,k=0;
    string a[200000];
    cin>>n;
    for(int l=0;l<n;l++){
        cin>>x;
        for(int j=0;j<x;j++){
            cin>>a[k];
			k++;
	    }}
	k=k-1; 
	for(int i=0;i<k;i++){
		if(a[i]!=a[k-i])
		b+=1;
		}
	cout<<b/2;
	return 0;
}   
