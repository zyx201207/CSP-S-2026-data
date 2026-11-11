#include<bits/stdc++.h>
using namespace std;
int a[10001];

int b[1001];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	int ans=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans+=1000; 
	else{ 
	ans=0;
	cout<<"0000";
	return 0;
	}
	for(int i=1;i<=3;i++){
			if(a[1]==b[1] && a[2]==b[2] && c1==c2) {
			ans+=100;
			break;
		}
			else ans+=0;
	}
			for(int i=1;i<=s1.size();i++){
				for(int j=1;j<=s2.size();j++){
			if(a[1]==b[1] && a[2]==b[2] && a[i]=='A' && b[i]=='B' ){ 
			ans+=10;
			break;
		}
			else if( b[i]=='C' && a[i]=='A' && a[1]==b[1] && a[2]==b[2]){
			ans+=10;
		}
			else if(a[1]==b[1] && a[2]==b[2] && b[i]=='A' && a[i]=='B'){ 
			ans+=10;
			break;
		}
			else if(b[3]=='A' && a[3]=='C' && a[1]==b[1] && a[2]==b[2]){
				 ans+=10;
				 break;
			 }
			else if(a[1]==b[1] && a[2]==b[2] && b[3]=='B'&& a[3]=='C') 
			{
				ans+=10;
				break;
			}
			else if(a[1]==b[1] && a[2]==b[2] && b[3]=='C' && a[3]=='B')
			{
				 ans+=10;
				 break;
			}
		
	}
}
	for(int i=1;i<3;i++){
			if(a[3]=='A' && b[3]=='B' && a[1]==b[1] && a[2]==b[2]) ans+=1;
			else if(a[3]=='B' && b[3]=='A' && a[1]==b[1] && a[2]==b[2]) ans+=1;
			else if(a[3]=='B' && b[3]=='C' && a[1]==b[1] && a[2]==b[2]) ans+=1;
			else if(a[3]=='C' && b[3]=='B' && a[1]==b[1] && a[2]==b[2]) ans+=1;
			else if(a[3]=='D' && b[3]=='F' && a[1]==b[1] && a[2]==b[2]) ans+=1;
			 else if(a[3]=='F' && b[3]=='D' && a[1]==b[1] && a[2]==b[2]) ans+=1;
			 else ans+=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

