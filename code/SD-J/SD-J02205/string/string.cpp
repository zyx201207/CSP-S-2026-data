#include<bits/stdc++.h>
using namespace std;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	string s,s1,s2,s3,s4;
	long long a;
	char b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	int m=s.size();
		if(m%2==0){
			for(int o=0;o<m/2;o++){
				char c=s[o];
				s1+=c;
			}
			for(int p=m/2;p<=m;p++){
				char c=s[p];
				s2+=c;
			}
		}
		if(m%2==1){
			for(int w=0;w<m/2;w++){
				char c=s[w];
				s1+=c;
			}
			for(int v=m/2+1;v<=m;v++){
				char c=s[v];
				s2+=c;
			}
		}
	for(int i=m/2-1;i>=0;i--)s4+=s2[i];
	for(int i=0;i<m/2;i++){
		char x=s1[i];
		char y=s4[i];
		
		if(x!=y)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
} 
