#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int ans[5],check[6]={1,1,1,2,0,2};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	memset(ans,0,sizeof(ans));
	
	bool flag=1;
	if(c1==c2){
		ans[1]=1;
		
		int p1=(s1[0]-'0')*10+(s1[1]-'0');
	    int p2=(s2[0]-'0')*10+(s2[1]-'0');
	    if(p1==p2){
	    	ans[2]=1;
	    	
	    	int st1=s1[2]-'A',st2=s2[2]-'A';
	        if(check[st1]==check[st2]){
	        	ans[3]=1;
	        	
	        	if(st1>st2) swap(st1,st2);
	        	if(st1==3 && st2==5) ans[4]=1;
	        	else if(st1+1==st2) ans[4]=1;
			}
		}
	}
	
	for(int i=1;i<=4;i++) cout<<ans[i];
	return 0;
}
/*
if(c1==c2) ans[1]=1;
	else flag=0;
	
	int p1=(s1[0]-'0')*10+(s1[1]-'0');
	int p2=(s2[0]-'0')*10+(s2[1]-'0');
	if(flag && p1==p2) ans[2]=1;
	else flag=0;
	
	int st1=s1[2]-'A',st2=s2[2]-'A';
	if(flag && check[st1]==check[st2]) ans[3]=1;
	else flag=0;
	
	if(st)
*/
