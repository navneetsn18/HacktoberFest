#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s1="abcde",s2="ace";
  int n=s1.length(),m=s2.length();
  int arr[n+1][m+1];
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
    {
      if(i==0 || j==0)
        arr[i][j]=0;
      else if(s1[i-1]==s2[j-1])
        arr[i][j]=arr[i-1][j-1]+1;
      else
        arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
    }
  }
  int x=n,y=m;
  vector<char> ans;
  while(arr[x][y]>0)
  {
    if(s1[x-1]==s2[y-1])
    {
      ans.push_back(s1[x-1]);
      y-=1;
    }
    x-=1;
  }
  for(auto t=ans.rbegin();t!=ans.rend();++t)
    cout<<*t;
  return 0;
}
