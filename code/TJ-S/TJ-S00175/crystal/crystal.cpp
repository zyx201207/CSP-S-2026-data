#include <bits/stdc++.h>
using namespace std;
long long n,m,a[600000],act,b[600000],c[600000],push=1e9,ptr,ans=1,f=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	for(int i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=0;i<n-2;i++){
		c[i]=b[i+1]-b[i];
	}
	if(m==0){
		//cout<<"*";
		for(int i=0;i<n;i++){
			if(a[i]==a[i+1]){
				ans++;
			}
		}
		if(ans==1){
			cout<<0;
		}else{
			cout<<ans;
		}
		return 0;
	}
	else{
		//cout<<"#";
		while(f==0){
			//cout<<"*#";
			sort(a,a+n,greater<int>());
			for(int i=0;i<n-1;i++){
		        b[i]=abs(a[i+1]-a[i]);
	        }
	        for(int i=0;i<n-2;i++){
		        c[i]=abs(b[i+1]-b[i]);
	        }
	        push=1e9;
			for(int i=0;i<n-2;i++){
				if(c[i]!=0){
					push=min(push,c[i]);
				}
			}
			for(int i=n-3;i>=0;i--){
				if(c[i]==push){
					ptr=i;
					//cout<<ptr<<'\n';
					break;
				}
			}
			if(abs(a[ptr+1]-a[ptr+2])<=m && a[ptr+1]!=a[ptr+2]){
				if(a[ptr+1]>a[ptr+2]){
					m-=a[ptr+1]-a[ptr+2];
					a[ptr+2]=a[ptr+1];
					//cout<<ptr<<'/'<<a[ptr]<<'\n';
				}else{
					m-=a[ptr+2]-a[ptr+1];
					a[ptr+1]=a[ptr+2];
					//cout<<ptr<<'/'<<a[ptr]<<'\n';
				}
			}else{
				f=1;
				break;
			}
			if(abs(a[ptr]-a[ptr+1])<=m && a[ptr]!=a[ptr+1]){
				if(a[ptr]>a[ptr+1]){
					m-=a[ptr]-a[ptr+1];
					a[ptr+1]=a[ptr];
					//cout<<ptr<<'/'<<a[ptr]<<'\n';
				}else{
					m-=a[ptr+1]-a[ptr];
					a[ptr]=a[ptr+1];
					//cout<<ptr<<'/'<<a[ptr]<<'\n';
				}
			}
			else{
				f=1;
				break;
			}
		}
		for(int i=0;i<n;i++){
			if(a[i]==a[i+1]){
				//cout<<a[i]<<'/'<<a[i+1];
				ans++;
			}
		}
		if(ans==1){
			//for(int i=0;i<n;i++){
				//cout<<a[i];
			//}
			cout<<0;
		}else{
			//for(int i=0;i<n;i++){
				//cout<<a[i];
			//}
			//cout<<endl;
			cout<<ans;
		}
		
	}
	return 0;
}
