#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1;
	int c2;
	char s1[3];
	char s2[3];
	int t;
	int ans1,ans2,ans3,ans4;
	ans1=0;
	ans2=0;
	ans3=0;
	ans4=0;
	cin>>c1;
	cin>>s1[0]>>s1[1]>>s1[2];
	cin>>c2;
	cin>>s2[0]>>s2[1]>>s2[2];
	
	if(c1==01){
		
		t=1;
    }
	if(c1==16){
		
		t=1;
	}
	if(c2==01){
		t++;	
	}
	if(c2==16){
		t++;
		
	}
	
	if(t==0){
		
		if(c1==c2){
			ans1=1;
			
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
				ans2=1;
				
				if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'){
					ans3=1;
					ans4=1;
				}else if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
					ans3=1;
				}else if(s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
					ans3=1;
					ans4=1;
				}else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
					ans3=1;
					ans4=1;
				}
			}
		}	
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	
	return 0;
}
