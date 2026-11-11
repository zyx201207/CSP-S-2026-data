#include<bits/stdc++.h>
using namespace std;
int n;
bool ac;
long long sum;
struct AB{
	int at;
	char ct;
};
AB a[200001],t; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].at>>a[i].ct;
	}
	int i1=0,i2=n-1;
    t.at=a[i1].at;
    t.ct=a[i1].ct;
    ac=0;
	while(i1<i2){
		if(ac){
			if(a[i1].at<t.at){
				if(t.ct!=a[i1].ct){
					sum+=a[i1].at;
				}
				t.at-=a[i1].at;
				i1++;				
			}
			else if(a[i1].at==t.at){
				if(t.ct!=a[i1].ct){
					sum+=a[i1].at;
				}
				i1++;
				i2--;
				t.at=a[i1].at;
				t.ct=a[i1].ct;				
			} 
			else{
				if(t.ct!=a[i1].ct){
					sum+=t.at;
				}
				t.ct=a[i1].ct;
				t.at=a[i1].at-t.at;
				ac=0;
				i2--;				
			}
		}
		else{
			if(t.at>a[i2].at){
				if(t.ct!=a[i2].ct){
					sum+=a[i2].at;
				}
				t.at-=a[i2].at;
				i2--;				
			}
			else if(a[i2].at==t.at){
				if(t.ct!=a[i2].ct){
					sum+=t.at;
				}
				i1++;
				i2--;
				t.at=a[i1].at;
				t.ct=a[i1].ct;				
			} 
			else{
				if(t.ct!=a[i2].ct){
					sum+=t.at;
				}
				t.ct=a[i2].ct;
				t.at=a[i2].at-t.at;
				ac=1;
				i1++;				
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
