#include<bits/stdc++.h>
using namespace std;
struct str{
	int length;
	char c;
}a[200002];
int n;
long long len,ans;
int main(){
	ifstream cin("string.in");
	ofstream cout("string.out");
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].length>>a[i].c;
		len+=a[i].length;
	}
	int id=0,iend=n-1;
	for(long long i=0;i<len/2;){
		i+=a[id].length;
		while(a[id].length>0){
			if(a[id].c!=a[iend].c){
				if(a[id].length>=a[iend].length){
					a[id].length-=a[iend].length;
					ans+=a[iend].length;
					iend--;
				}else{
					a[iend].length-=a[id].length;
					ans+=a[id].length;
					a[id].length=0;
				}
			}else{
				if(a[id].length>=a[iend].length){
					a[id].length-=a[iend].length;
					iend--;
				}else{
					a[iend].length-=a[id].length;
					a[id].length=0;
				}
			}
		}
		id++;
	}
	cout<<ans;
	return 0;
}
