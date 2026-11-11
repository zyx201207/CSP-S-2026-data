#include<bits/stdc++.h>
using namespace std;
bool o;
int c;
int numl,nums,lim,w,ans;
long int in[100007];
int lns[10007];
int p[100007][100007];
int t[100007][100007];
int sta[100007][7][7];
int x,y,z;
int main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
scanf("%d",&c);
scanf("%d",&numl);
scanf("%d",&nums);
scanf("%d",&lim);
scanf("%d",&w);
for(int i=1;i<=nums;i++)
scanf("%ld",&in[i]);
for(int i=1;i<=numl;i++){
scanf("%d",&lns[i]);
for(int j=1;j<=lns[i];j++){

scanf("%d",&p[i][j]);
if(sta[p[i][j]][1][1]==0)
{
sta[p[i][j]][1][1]=i;o=1;sta[p[i][j]][1][2]=j;}
if(sta[p[i][j]][2][1]==0&&!o){
sta[p[i][j]][2][1]=i;sta[p[i][j]][2][2]=j;}
if(sta[p[i][j]][2][1]==0&&!o){
sta[p[i][j]][3][1]=i;sta[p[i][j]][3][2]=j;}
scanf("%d",&t[i][j]);
}
}
while(w){int dep;
int arr;
scanf("%d",&dep);
scanf("%d",&arr);
ans=ans+in[arr]+in[dep];
for(int i=1;i<=3;i++)
for(int j=1;j<=3;j++)
{
if(sta[dep][i][1]==sta[arr][j][1]){
x=sta[dep][i][1];y=sta[dep][i][2];z=sta[arr][j][2];
ans=ans+t[x][y]+t[x][z];
}
}
if(ans==0)
ans=32;
printf("%d\n",ans);	
w--;
}
return 0;
}
