#include<bits/stdc++.h>
using namespace std;
int a[10];
void print(){
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string C1,s1,C2,s2;
	cin>>C1>>s1>>C2>>s2;
	int S1,S2,c1,c2;
	S1=s1[0]*10+s1[1];
	S2=s2[0]*10+s2[1];
	c1=C1[0]*10+C1[1];
	c2=C2[0]*10+C2[1];
		
	if(c1!=c2){
		print();
	}else{
		a[0]=1;
		if(S1!=S2) print();
		else{
			a[1]=1;
			if(s1[2]=='A'){
				if(s2[2]=='B'){
					a[2]=1;a[3]=1;
					print();
				}else if(s2[2]=='C'){
					a[2]=1;a[3]=0;
					print();
				}else print();
			}else if(s1[2]=='B'){
				if(s2[2]=='A'){
					a[2]=1;a[3]=1;
					print();
				}else if(s2[2]=='C'){
					a[2]=1;a[3]=1;
					print();
				}else print();			
			}else if(s1[2]=='C'){
				if(s2[2]=='B'){
					a[2]=1;a[3]=1;
					print();
				}else if(s2[2]=='A'){
					a[2]=1;a[3]=0;
					print();
				}else print();			
			}else if(s1[2]=='D'){		
				if(s2[2]=='F'){
					a[2]=1;a[3]=1;
					print();
				}else print();	
			}else{
				if(s2[2]=='D'){
					a[2]=1;a[3]=1;
					print();
				}else print();
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
