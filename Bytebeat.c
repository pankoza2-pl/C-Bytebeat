#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

int main()
{
    HWAVEOUT hWaveOut;
    WAVEFORMATEX wfx;
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nChannels = 1;
    wfx.nSamplesPerSec = 24000;
    wfx.nAvgBytesPerSec = 24000;
    wfx.nBlockAlign = 1;
    wfx.wBitsPerSample = 8;
    wfx.cbSize = 0;

    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[12000 * 60];

    for (DWORD t = 0; t < sizeof(buffer); t++)
    {
        buffer[t] = //put your bytebeat here
    }

    WAVEHDR wHeader;
    wHeader.lpData = buffer;
    wHeader.dwBufferLength = sizeof(buffer);
    wHeader.dwBytesRecorded = 0;
    wHeader.dwUser = 0;
    wHeader.dwFlags = 0;
    wHeader.dwLoops = 0;
    wHeader.lpNext = 0;
    wHeader.reserved = 0;

    waveOutPrepareHeader(hWaveOut, &wHeader, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &wHeader, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &wHeader, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
    Sleep(INFINITE);
}