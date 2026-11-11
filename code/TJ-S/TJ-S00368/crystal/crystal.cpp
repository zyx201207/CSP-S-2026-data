#include<bits/stdc++.h>
using namespace std;

int n,m;
int cry[500000];
int main(){
	ifstream in;
	in.open("crystal.in");
	ofstream out;
	out.open("crystal.out");
	
	in>>n>>m;
	
	double all=0;
	for(int i=0;i<n;i++){
		in>>cry[i];
		all+=cry[i];
	}
	sort(cry,cry+n);
	
	double cre=all/n;
	//cout<<cre;
	
	int l=0;
	int same=0;
	for(int i=n-1;i>=0;i--){
		float l1=abs(cry[i]-cre);
		float l2=abs(cry[l]-cre);
		
		//cout<<l1<<" "<<l2<<" "<<l<<"\n";
		if(l1<l2){
			l=i;
		}
		
		//cout<<cry[i];
	}
	//cout<<l;
	
	int count=0;
	for(int i=l;i>=0;i--){
		
		if(cry[i]==cry[l]){
			same++;
		}
		
		if(cry[i]<cry[l] && cry[l]-cry[i]>=0){
			//cout<<cry[l]-cry[i]<<" "<<cry[l]<<" "<<cry[i]<<"\n";
			m-=cry[l]-cry[i];
			count++;
		}
		if(m==0){
			break;
		}
	}	
	
	out<<count+same;
	in.close();
	out.close();
	return 0;
}

