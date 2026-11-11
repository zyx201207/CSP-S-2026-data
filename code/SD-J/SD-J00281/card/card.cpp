#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	char l[n]={};
	int c[m]={};
	char b[n]={};
	a=n;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int i=0;i<n;i++){
	string w="";
		for(int j=i;j<n;j++){
			if(w.find(l[j])==-1){
				w+=l[j];
			}else{
			int g=w.find(l[j]);
			w.erase(g);
			w+=l[j];				
			}
		}
		for(int f=0;f<w.size();f++){
			b[f]=w[f];
		}
		for(int k=49;k<=49+m-1;k++){
			for(int f=0;f<w.size();f++){
				int t=int(char(b[f]));
				if(k==t){
					c[k-49]+=1;
					
				}
			}
			
		}
			
			}
		
	for(int r=0;r<m;r++){
			cout<<c[r]<<' ';
				
			}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
