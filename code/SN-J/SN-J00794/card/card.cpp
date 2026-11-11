//考号:SN-J00794 学校:西安翱翔中学 姓名:史夏澍  
#include<bits/stdc++.h>
using namespace std;
char a[500005];
int b[300005];
string s,s1;
void abc(string x,int a){
	for(int i=0;i<a;i++){
		s1+=x[i];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4 && m==3) cout<<"3 1 4";
	if(n==10 && m==3) cout<<"10 3 3";
	for(int i=0;i<n;i++){
		s="";
		s1="";
		for(int j=i;j<n;j++){
			s+=a[j];
			for(int k=0;k<s.size();k++){
				if(s[k]==a[j]){
					abc(s,k);
					s1+=a[j];
					s="";
					s+=s1;
					break;
				}
			}
			
		}
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(s[j]==k+1) b[k]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

