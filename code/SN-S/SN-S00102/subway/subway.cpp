#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k1,k2,sum;
	int str[m];
	int str1[m/2];
	int str2[m/2];
	int str3[m/2];
	int str4[m/2];
	sum=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<c;i++){
		for(int i=0;i<m/2;i++){
			cin>>str[i];
		}
		cin>>k1;
		for(int i=0;i<m/2;i++){
			cin>>str1[i]>>str2[i];
		}
		for(int i=0;i<m/2;i++){
			cin>>str3[i]>>str4[i];
		}
		for(int i=0;i<m/2;i++){
			if(str1[i]=str3[i]){
				sum=sum+str2[i]+str4[i];
			}
		}
		
		cout<<sum+20<<endl;
	}
	return 0;
}
