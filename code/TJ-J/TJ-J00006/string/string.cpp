#include<bits/stdc++.h>
using namespace std;
int main(){
	long long e,r[100000];
	string q,w,v;
	int g=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>e;
	for(int i=1;i<=e;i++){
		cin>>r[i]>>w;v+=w;
		for(int j=1;j<=r[i];j++){
			q+=w;
		}
		if(r[i]!=r[i-1]){
		g=1;	
		}
	}
	if(g==0){
		
	int m=0;
	if(v.size()%2==0){
		for(int i=0;i<v.size()/2;i++){
			if(v[i]!=v[v.size()-1-i]){
				m++;
			}
	}
	}else{
			for(int i=0;i<v.size()/2;i++){
				if(v[i]!=v[v.size()-1-i]){
				m++;
			}
	}
	}
	
	cout<<m;
	}
	int m=0;
	if(q.size()%2==0){
		for(int i=0;i<q.size()/2;i++){
			if(q[i]!=q[q.size()-1-i]){
				m++;
			}
	}
	}else{
			for(int i=0;i<q.size()/2;i++){
				if(q[i]!=q[q.size()-1-i]){
				m++;
			}
	}
	}
	
	cout<<m;
	return 0;
} 
