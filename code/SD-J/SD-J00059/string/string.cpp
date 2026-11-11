#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout) ;

	string s;
	int n,len;
	cin>>n;
	int a;
	char x;
	while(n--){
		len+=a;
		while(a--){
			s+=x;
		}
		long long i=0,j=len-1;
		while(i<j){ 
			if(s[i]=s[j]){
			s[a]++;
			i++,j--;
		}
		}	 
	}
	cout<<s;
	return 0; 
}

