//SN-J00791 余思弦 西安工业大学附属中学 
#include<bits/stdc++.h>
using namespace std;
string s;
int n,c=0,a;
long long shu[1000001];
char d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>d;
		s[i]=d;
		shu[i]=a;
		
	}int j;
	for(int i=0;i<n/2;i++){
		j=i;
		while(shu[i]!=0){
			if(s[i]!=s[n-j-1]){
				if(shu[i]-shu[n-j-1]<0){
					c+=shu[n-j-1]-shu[i];
				}else c+=shu[n-j-1];
			}
			if(shu[i]-shu[n-j-1]<=0){
				shu[n-j-1]-shu[i];
				shu[i]=0;
			}else{
				shu[i]=shu[i]-shu[n-j-1];
				shu[n-j-1]=0;
			}
			j++;
		}
		
	}
	cout<<c;
	return 0;
}
