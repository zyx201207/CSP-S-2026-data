/*
 * untitled.cxx
 * 
 * Copyright 2026 NOI <noi@G18-D07>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <bits/stdc++.h>
using namespace std;
int a[2000006];
int main()
{	freopen("math","r","migrate.in");
	freopen("math","w","migrate.out");
	int c,t,n,d,sum=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			sum++;
		}
		int e=0;
		while(sum!=0){
			if(a[sum]-a[sum-1]<=t){
				if(a[sum-1]-1<=t){
					e++;
					sum--;
				}
			}
			else{
				sum--;
				continue;
		}
		cout<<e;
	}
	return 0;
}

