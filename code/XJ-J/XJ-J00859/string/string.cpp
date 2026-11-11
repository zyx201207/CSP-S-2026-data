#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long s[n],sz[n]={0};
	string zm[n],zmz[n]={""};
	for(long long i=0;i<n;i++){
		cin>>s[i]>>zm[i];
	}
	string x=zm[0];
	string zz;
	long long c=0,j=0,r=0,z,z1,zx,su=0;
	for(long long i=0;i<n;i++){
		if(zm[i]==x){
			c+=s[i];
			su+=s[i];
			r=0;
		}
		else{
			sz[j]=c;
			zmz[j]=x;
			x=zm[i];
			c=s[i];
			j++;
			r=1;
			su+=s[i];
		}
	}
	if(r==0){
		sz[j]=c;
		zmz[j]=x;
	}
	if(su%2==0){
		z=su/2;
	}
	else{
		z=(su+1)/2;
	}
	z1=z;

	for(int i=0;i<n;i++){
		if(sz[i]!=0 and zmz[i]!=""){
			if(sz[i]>=z1){
				zz=zmz[i];
				zx=i;
				break;
				
			}	
			else{
				z1-=sz[i];
			}
		}
	}
	vector<int> sl;
	vector<string> zml;
	for(int i=0;i<n;i++){
		if(sz[i]!=0 and zmz[i]!=""){
			if(zx==i){
				if(z1>1){
					if(su%2!=0){
						sl.push_back(z1-1);
						zml.push_back(zz);
						sl.push_back(1);
						zml.push_back(zz+"*");
					}
					else{
						sl.push_back(z1);
						zml.push_back(zz+"*");
					}
					sl.push_back(sz[i]-z1);
					zml.push_back(zz);
				}
				else{
					sl.push_back(z1);
					zml.push_back(zz+"*");
					sl.push_back(sz[i]-z1);
					zml.push_back(zz);
				}
			}
			else{
				sl.push_back(sz[i]);
				zml.push_back(zmz[i]);
			}
				
				
		}
		
	}
	int cou=0;
	for(int i=0;i<sl.size();i++){
		if(zml[i].length()==2){
			break;
		}
		else{
			cou+=sl[i];
		}
	}
	cout<<cou;
	return 0;
}