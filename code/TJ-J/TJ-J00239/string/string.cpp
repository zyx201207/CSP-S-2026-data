#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,m=0;
string s;
long long y=0;
struct dete{
	long long a;
	char c;
}w[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>w[i].a>>w[i].c;
	}
	long long l=0,r=n-1;
	while(r>=l){
		if(w[l].a<=0){
			l++;
		}
		if(w[r].a<=0){
			r--;
		}
		y=min(w[l].a,w[r].a);
		if(w[l].c!=w[r].c){	
			m+=y;
		}
		if(l!=r){
			w[l].a-=y;
			w[r].a-=y;
		}else{
			break;
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
