#include<bits/stdc++.h> 
using namespace std;
const int N=1e8+10; 
long long n,g;
long long a[N],cnt;
char b[200010];
string s1,q,h,s2,s3,s4; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

//特判<1> 
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	
//输入 
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		cnt+=a[i];
	}
	
//特判<2> 
	bool tf=false;
	int k=0;
	for(int i=0;i<n;i++){
		if(b[i]==b[i+1]){
			k++;
		}
		if(k==n-1){
			cout<<0;
			return 0;
		}
	}
	
//拼接 
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s1[g]=b[i];
			s4[g]=b[i];
			g++;
		}
	}
//测试拼接  
//	for(int i=0;i<cnt;i++){
//		cout<<s1[i];
//	}

	for(int i=0;i<cnt/2;i++){
		s2[i]=s1[i];
	}
	int m=0,l=0;
	for(int i=cnt/2;i>=0;i--){
		s2[i]=s1[i];
		if(cnt/2==0){
			if(s2[i]!=s4[l+i]){
				m++;
			}
		}else if(cnt/2!=0){
			if(s2[i]!=s4[l+i+1]){
				m++;
			}
		}
		
//		cout<<s4[l+cnt/2];
		l++;
	}
//	for(int i=cnt;i>=0;i--){
//		cout<<s2[i];
//	}
	cout<<m;
	return 0; 
	
//测试样例
//4
//2 a
//1 b
//1 a
//1 d

	return 0;
}
//1992 09 29
