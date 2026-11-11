#include<bits/stdc++.h>
using namespace std;

int arr[204];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int c1,c2;string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		int pai1=(s1[0]-'0')*10+(s1[1]-'0');
		int pai2=(s2[0]-'0')*10+(s2[1]-'0');
		if(pai1!=pai2){
			cout<<"1000";
		}else{
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='D'||s2[2]=='E'){
					cout<<"1100";
				}else{
					arr[s1[2]]++;
					arr[s2[2]]++;
					bool flag=true;
					for(int i=64;i<=70;i++){
						if(arr[i]&&arr[i+1]){
							cout<<"1111";flag=false;break;
						}
					}
					if(flag){
						cout<<"1110";
					}
				}
			}else{
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					cout<<"1100";
				}else{
					arr[s1[2]]++;
					arr[s2[2]]++;
					bool flag=true;
					for(int i=64;i<=70;i++){
						if(arr[i]&&arr[i+1]){
							cout<<"1111";flag=false;break;
						}
					}
					if(flag){
						cout<<"1110";
					}
				}
			}
		}
	}
	
	return 0;
}
