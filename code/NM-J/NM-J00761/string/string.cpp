#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0;
	cin>>n;
	vector<long long>vec;
	string c;
	for(long long i=0;i<n;i++){
		long long a=0;
		cin>>a;
		vec.push_back(a);
		char b='0';
		cin>>b;
		c+=b;
	}
	int j=0;
	int w=0;
	long long o=0;
	vector<long long>vec1;
	 string c1;
	for(long long i=0;i<n;i++){
		if(i==n-1){
			for(int m=0;m<=j;m++){
				o+=vec[i-m];
			}
			vec1.push_back(o);
			c1+=c[i];
			j=0;
			o=0;
			continue;
		}
		if(c[i]==c[i+1]){
			++j;
		}else{
			for(int m=0;m<=j;m++){
				o=o+vec[i-m];
			}
			vec1.push_back(o);
			c1+=c[i];
			j=0;
			o=0;
		}
	}
//	cout<<c1;
//	for(int i=0;i<vec1.size();i++){
//		cout<<vec1[i]<<" ";
//	} 
	if(c1.length()==1){
		cout<<0;
		return 0;
	}

	int u=0;
	long long k=0;
	long long n1=c1.length();
	int u1=n1-1;
	int r=0;
	while(u<u1){
		
		if(c1[u]==c1[u1]){
			k+=max(vec1[u],vec1[u1])-min(vec1[u],vec1[u1]);
			if(vec1[u]>vec[u1]){
				vec1[u]-=vec1[u1];
				u1--;
			}else if(vec1[u]<vec1[u1]){
				vec1[u1]-=vec1[u];
				u++;
			}else{
				u++;
				u1--;
			}
		}else{
			k+=min(vec1[u],vec1[u1]);
//			int y=max(vec1[u],vec1[u1])-min(vec1[u],vec1[u1]);
			if(vec1[u]>vec1[u1]){
				vec1[u]-=vec1[u1];
				u1--;
			}else if(vec1[u]<vec1[u1]){
				vec1[u1]-=vec1[u];
				u++;
			}else{
				u++;
				u1--;
			}
		}
	}
	cout<<k;
		
	

		
				
		
		
		
	
	
	
	
	
	return 0;
} 
