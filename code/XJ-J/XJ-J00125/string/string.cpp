#include<bits/stdc++.h>
using namespace std;
const int N=5e7+10;
int n,x=1,i=1,y=1,cnt,a[N];
char c[N];
long long int sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a[x]>>c[x];
		sum+=a[x++];
	}
	
	int k=sum/2+1;
	for(int i=0;i<sum;i++){
		if(a[y]>0){
			 s+='W';
			 s[i]=c[y];
			 a[y]--;
		}
		else y++,i--;
	}
	for(int i=0;i<k;i++){
		if(s[i]!=s[sum-i-1]) cnt++;
	}
	cout<<cnt;
	return 0; 
}
