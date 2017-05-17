// WIP 

FILE *userdata = fopen_s("userdata.json", "r+");
if (userdata)
{
  fseek (userdata, 0, SEEK_END);
  length = ftell (userdata);
  fseek (userdata, 0, SEEK_SET);
  buffer = malloc (length);
  if (buffer)
  {
    fread (buffer, 1, length, userdata);
  }
  fclose (userdata);
}

if (buffer)
{
  if
}
