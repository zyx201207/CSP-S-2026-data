#include <bits/stdc++.h>
using namespace std;
int a[1000000000000];
int b[1000000000000];
int p=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	   cin>>a[i];

for(int i=0;i<n;i++){

while (m>0)
{
if (a[i+1]-a[i]<=a[i+2]-a[i+1]&&a[i+1]-a[i]>0&&m>0)
      	a[i]++;
      	m--;}
    while(m>0)  	
{
if (a[i+1]=a[i])
     a[i+1]++;
     m--;}
while (m>0)
{
if (a[i+1]-a[i]>0&&m>0)
    a[i]++;
    m--;}}
for (int i=0;i<n;i++)
	 if (a[i]=a[i+1])
p++;	  
	cout<<p;
	return 0;
}
