#include<bits/stdc++.h>
using namespace std;
int n,x[1000005],j=1,cnt,k;
char y[1000005];
string a;
int main(){
	freopen("string.in","a",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		while(x[i]--){
			a+=y[i];
			k++;
		}
	}
	for(int i=0;i<a.size();i++){
		cout<<y[i]<<" ";
	}
	for(int i=a.size()+1;i<=a.size();i++){
		
		if(a[i]==a[i-j]){
			
			continue;
		}
		else{
			cnt++;
		} 
		j+=2;
	}
	cout<<cnt<<endl;
	return 0;
} 
