#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector <int> numz (1e12+5,0);
vector <int> numf (1e12+5,0);

int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	int n=0;
	long long m=0£¬max=0,min=0; 
	cin>>n>>m;
	vector <long long> cl (n);
	for(int i=0;i<n;i++){
		cin>>cl[i];
		if(cl[i]>0){
			numz[cl[i]]++;
			if(max<cl[i]){
				max=cl[i];
			}
		}
		else{
			numf[cl[i]]++;
			if(min>cl[i]){
				min=cl[i];
			}
		}
	} 
	sort(cl.begin(),cl.end());
	int ma=0;
	for(int i=0;i<max+1&&i<min+1;i++){
		if(numz[i]>ma){
			ma=i;
		}
	}
	
	
	
	return 0;
} 
