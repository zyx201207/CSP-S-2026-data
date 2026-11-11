#include<bits/stdc++.h>
using namespace std;
const int a = 200005;
long long m[a],gzc=0;
char n[a];
int b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>b;
	for(int i = 1;i<=b;i++){
		cin>>m[i]>>n[i];
	}
	long long l = 1,r = b;
	while(l<=r){
		if(n[l]==n[r]){
			if(m[l]==m[r]){
				l+=1;
				r-=1;
			}
			else if(m[l]>m[r]){
				m[l]-=m[r];
				r-=1;
			}
			else{
				m[r]-=m[l];
				l+=1;
			}
		}
		else{
			if(m[l]==m[r]){
				gzc+=m[l];
				l+=1;
				r-=1;
			}
			else if(m[l]>m[r]){
				gzc+=m[r];
				m[l]-=m[r];
				r-=1;
			}
			else{
				gzc+=m[l];
				m[r]-=m[l];
				l+=1;
			}	
		}
	}
	cout<<gzc;
	return 0;
}
