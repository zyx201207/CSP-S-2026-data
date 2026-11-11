#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,n2,d2,su1,su2;
	cin>>c>>t;

	for(int i=0;i<25;i++){
		for(int i=0;i<t;i++){
			cin>>n>>d;
			int s1[n];
			
			for(int i=0;i<n;i++){
				cin>>s1[i];
			}
			cin>>n2>>d2;
			int s2[n2];
			
			for(int i=0;i<n2;i++){
				cin>>s2[i];
			}
			int w=0;
			su1=0;
			su2=0;
			for(int i=0;i<n;i++){
				if(s1[i+1]-s1[i]==d){
					continue;
				}
				if(s1[i+2]-s1[i]==d&&s1[i+3]-s1[i+2]==1){
					su1++;
				}else if(s1[i+3]-s1[i]==d&&s1[i+4]-s1[i+3]==1){
					su1++;
				}else if(s1[i+4]-s1[i]==d&&s1[i+5]-s1[i+4]==1){
					su1++;
				}else if(s1[i+1]-s1[i]==1&&s1[i+2]-s1[i+1]==d){
					su1++;
				}else{
					continue;
				}
				
			}
			for(int i=0;i<n;i++){
				if(s2[i+1]-s2[i]==d){
					continue;
				}
				if(s2[i+2]-s2[i]==d&&s2[i+3]-s2[i+2]==1){
					su2++;
				}else if(s2[i+3]-s2[i]==d&&s2[i+4]-s2[i+3]==1){
					su2++;
				}else if(s2[i+4]-s2[i]==d&&s2[i+5]-s2[i+4]==1){
					su2++;
				}else if(s2[i+1]-s2[i]==1&&s2[i+3]-s2[i+1]==d){
					su2++;
				}else{
					continue;
				}
			}
			cout<<su1<<"\n"<<su2;
			n=0;
			d=0;
			n2=0;
			d2=0;
		}
	}
	return 0;
}
